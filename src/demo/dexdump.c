/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */ 
#include "dexbox/dexbox.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * main
 */
tb_int_t main(tb_int_t argc, tb_char_t** argv)
{
    // init tbox
    //if (!tb_init(tb_null, tb_null)) return -1;
    if (!tb_init(tb_null, tb_native_allocator())) {

        printf("tb_init error \n");
        return -1;
    }
    printf("Dumping %s \n",argv[1]);
    // load dex file
    dx_file_ref_t dexfile = dx_file_load_from_url(argv[1], tb_true);
    
    if (dexfile)
    {
        printf("[+] parse success ,preparing  dumping\n");
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

    // ok
    return 0;
}
