#include "module0.hpp"
#include <vector>

using namespace std;
using namespace sc_core;

//int control[256];

unsigned int length;

module0::module0(sc_module_name name) : sc_module(name)
{
    module0_module_socket.register_b_transport(this, &module0::b_transport);

    SC_REPORT_INFO("module0", "Constructed.");
    SC_THREAD(process);
}

module0::~module0()
{
    SC_REPORT_INFO("module0", "Destcructed.");
}

void module0::b_transport(pl_t& p1, sc_time& offset)
{   
    tlm_command cmd     = p1.get_command();
    sc_dt::uint64 addr         = p1.get_address();
    unsigned char *data = p1.get_data_ptr();
     length = p1.get_data_length();


    switch(cmd)
    {
        case TLM_WRITE_COMMAND:
            control = *((int*)data);
            cout << control << ' '; 
    for(int i = 0; i < length; i++)
    {
    
            control[addr++] = data[i];
            //control[i] = *((int*)data);
            //i++;
            p1.set_response_status(TLM_OK_RESPONSE);
            //cout << control[i] << endl;
    }

        break;

        case TLM_READ_COMMAND: 
        break;

        default:
            p1.set_response_status(TLM_COMMAND_ERROR_RESPONSE);
            SC_REPORT_ERROR("MODULE0", "TLM_wrong_address");
        break;
    }
}

void module0::process()
{
    //vector <int> v = control;
    //int n = control;
    int n[length];
    for(int i = 0; i < length; i++)
    {   
        n[i] = control; 
        cout << n[i] << endl;
    }

    for(int i = 0; i < length; i++)
    {
    
        pfifo -> write(n[i]);
        cout << n[i] << endl;
    }
}