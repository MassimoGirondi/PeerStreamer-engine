#include<malloc.h>
#include<assert.h>
#include<psinstance.h>

void psinstance_create_test()
{
	struct psinstance * ps=NULL;

	//No parameters
        ps = psinstance_create(NULL);
	assert(ps);     
	psinstance_destroy(&ps);

        //BootStrap node
	ps = psinstance_create("port=6700");
	assert(ps);  // source created
	psinstance_destroy(&ps);

        //Invalid port      
	ps = psinstance_create("port=80000");
	assert(ps==NULL);  

	ps = psinstance_create("bs_addr=127.0.0.1,port=6000,bs_port=6001");
	assert(ps);  
	psinstance_destroy(&ps);

	fprintf(stderr,"%s successfully passed!\n",__func__);
}

int main()
{
	psinstance_create_test();
	return 0;
}
