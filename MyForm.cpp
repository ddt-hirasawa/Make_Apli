#include "MyForm.h"

using namespace Make_Application;

[STAThreadAttribute]

int main() {

	MyForm fm;
	fm.ShowDialog();
	return 0;
}
