#include "coll.hpp"

namespace comm
{
	using namespace sc_core;
	using namespace std;

	coll::coll(sc_module_name n) : sc_module(n)
	{
		pp.bind(s0);
		cout << name() << " constructed.\n";
		SC_THREAD(process);
     		//SC_THREAD(read);
                //sensitive << f1;
	}

	void module1::process()
	{
		while(1)
		{
			if (fifo->num_available())
			{
				int v = fifo->read();
				cout << name() << "_read:_" << v << endl;
				s0.write(v);
			}
			wait(1, SC_NS);
		}
	}

}
