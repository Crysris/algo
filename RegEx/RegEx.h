#include "../etc/utils.h"





class RegEx{
	public:
		string reg_ex;
		string input_str;
		void init(string _reg_rx);
		void match();
};