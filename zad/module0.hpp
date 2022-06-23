#ifndef _MODULE0_HPP_
#define _MODULE0_HPP_

#include <systemc>

namespace comm
{
using namespace sc_core;

SC_MODULE(module0)
{
public:
	SC_HAS_PROCESS(module0);

	module0(sc_module_name);

	sc_in<int> m0in;
	sc_port< sc_ fifo_out_if <int> > fifo ;
	sc_out<int> m0out;
	
protected:
	void process();
};

}

#endif
