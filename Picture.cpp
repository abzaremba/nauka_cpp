#include "Picture.h"
//#include <iostream>
#include <string>


Picture frame(const Picture& pic)
{
	return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
	return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
	return new VCat_Pic(t.p, b.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture)
{
	const Pic_base::ht_sz ht = picture.p->height();
	for (Pic_base::ht_sz i = 0; i != ht; ++i) {
		picture.p->display(os, i, false);
		os << std::endl;
	}
	return os;
}

Pic_base::wd_sz String_Pic::width() const
{
	Pic_base::wd_sz n = 0;
	for (Pic_base::ht_sz i = 0; i != data.size(); ++i)
		n = std::max(n, data[i].size());
	return n;
}

void String_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
	wd_sz start = 0; 

	// wrte th erow if we're still in range
	if (row < height()) {
		os << data[row];
		start = data[row].size();
	}

	// pad the output if necessary
	if (do_pad)
		pad(os, start, width());
}


void VCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
	wd_sz w = 0;
	if (row < top->height()) {
		// in the top subpicture
		top->display(os, row, do_pad);
		w = top->width();
	} else if (row < height()) {
		bottom->display(os, row - top->height(), do_pad);
		w = bottom->width();
	}
	if (do_pad)
		pad(os, w, width());
}

void HCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
	left->display(os, row, do_pad || row < right->height());
	right->display(os, row, do_pad);
}

void Frame_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
	if (row >= height()) {
		// out of range
		if (do_pad)
			pad(os, 0, width());
	} else {
		if (row == 0 || row == height() - 1) {
			// top or bottom
			os << std::string (width(), '*');
		} else if (row == 1 || row == height() - 2) {
			// second or one but last row
			os << "*";
			pad(os, 1, width() - 1);
			os << "*";
		} else {
			// interior row
			os << "*";
			p->display(os, row - 2, true);
			os << "*";
		}
	}
}