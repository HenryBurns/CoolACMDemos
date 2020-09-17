#include <cstdio>

struct Foo {
	const char* message;
	void goo();
};

void Foo::goo() {
	std::printf("%s", this->message);
}

extern "C" void _ZN3Foo3gooEv(Foo *f);

int main() {
	Foo f{"Test\n"};
	_ZN3Foo3gooEv(&f);
}
