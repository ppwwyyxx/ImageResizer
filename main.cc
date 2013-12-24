// File: main.cc
// Date: Mon Dec 23 14:59:30 2013 +0800
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
	ImageResizer resizer(img);
	resizer.resize(450, 512);
	GreyImg energy(resizer.energy);
	imgptr energyimg = make_shared<Img>(energy);
	FileRender render(energyimg, "out.png");
	render.finish();


	imgptr result = make_shared<Img>(resizer.result);
	FileRender rd2(result, "result.png");
	rd2.finish();
}


int main(int argc, char* argv[]) {
	test_energy();
}
