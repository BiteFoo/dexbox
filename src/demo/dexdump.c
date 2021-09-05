/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */ 
#include "dexbox/dexbox.h"


/**
 * 
 * origin call
 * 
 **/



void dump_dex(tb_char_t* url){

// init tbox
    //if (!tb_init(tb_null, tb_null)) return -1;
    if (!tb_init(tb_null, tb_native_allocator())) {

        printf("tb_init error \n");
        return -1;
    }
    // load dex file
    dx_file_ref_t dexfile = dx_file_load_from_url(url, tb_true);
    
    if (dexfile)
    {
        // printf("[+] parse success ,preparing  dumping\n");
        printf("\n---------------------DUMP DEX OPCODE--------------------\n\n");
        // dump dex file
        dx_file_dump(dexfile);

        // exit dex file
        dx_file_exit(dexfile);
    }else{
        printf("[-] Load dex failed.\n");
    }

    // exit tbox
    tb_exit();
}


/**
 * new call
 * **/

void new_dump_dex(tb_int_t argc,tb_char_t** argv)
{

    if(argc <2){
        printf("Usage: ./dex_dump /path/to/dex -h");
        return;
    }

    for(tb_int_t i = 0; i< argc; ++i)
        printf(" %d - %s\n",i,argv[i]);
    
    dump_dex(argv[1]);


}

/* //////////////////////////////////////////////////////////////////////////////////////
 * main
 */
tb_int_t main(tb_int_t argc, tb_char_t** argv)
{
    
    new_dump_dex(argc,argv);
    // ok
    return 0;
}
