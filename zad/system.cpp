#ifndef _SYS_CPP_
#define _SYS_CPP_

#include <systemc>
#include "system.hpp"

namespace comm
{
using namespace sc_core;

SC_MODULE(system)
{
public:
	SC_HAS_PROCESS(system);

	system(sc_module_name);

protected:

};


}
#endif
