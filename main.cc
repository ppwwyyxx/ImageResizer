// File: main.cc
// Date: Sun Dec 22 12:41:31 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <iostream>
#include "render/filerender.hh"
#include "planedrawer.hh"
#include "resizer.hh"
#include <ctime>
#include <cassert>

using namespace std;
using namespace Magick;

bool TEMPDEBUG = false;

void test_energy() {
	Img img("lenna.png");
	cout << &img << endl;
	ImageResizer resizer(img);
	resizer.resize(499, 500);
	GreyImg energy(resizer.energy);
	imgptr energyimg = make_shared<Img>(energy);
	FileRender render(energyimg, "out.png");
	render.finish();
}


int main(int argc, char* argv[]) {
	test_energy();
}
