#ifndef _SYS_HPP_
#define _SYS_HPP_

#include <systemc>
#include "module0.hpp"
#include "module1.hpp"

namespace comm
{
using namespace sc_core;

SC_MODULE(system)
{
public:
	SC_HAS_PROCESS(system);

	system(sc_module_name);

	sc_in<int> pnum;
	//sc_out<int> start;
	sc_export< sc_fifo_out_if<int> > pp;
        //sc_signal<bool> s0, s1;
        //sc_signal<int> s2, s3, s4;
protected:

	rnd_gen g0;
        rnd_gen g1;
        rnd_gen g2;
	coll c0;
};


}
#endif
