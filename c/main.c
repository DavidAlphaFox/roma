/* 
 * ROMA client.
 * File:   main.c
 * Author: yosuke hara
 */

#include <stdio.h>
#include <stdlib.h>
#include "roma_client.h"

#define RMC_STATUS_NOT_STORED      "NOT_STORED"
#define RMC_STATUS_SERVER_ERROR    "SERVER_ERROR"

void test_serialize() {
    rmc_value_info valinfo1;
    valinfo1.value = "value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008-value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008 value-test-008";
    valinfo1.length = 3599;    
    rmc_set("test-s-key-0001", valinfo1, 0);
    
    rmc_get("test-s-key-0001");
}

void test_simple() {
    rmc_value_info valinfo1;
    valinfo1 = rmc_get("e-empty-test-cp-key-0001");
    //printf("[%s]\n", valinfo1.value);

    valinfo1.length = 56;
    valinfo1.value = "test-cp-value-0001-test-cp-value-0001-test-cp-value-0001";

    rmc_set("test-cp-key-0001", valinfo1, 0);
    rmc_get("test-cp-key-0001");
}

void test_complex() {

    // set => get
    rmc_value_info valinfo1;
    valinfo1 = rmc_get("e-empty-test-cp-key-0001");
    //printf("[%s]\n", valinfo1.value);

    valinfo1.length = 56;
    valinfo1.value = "test-cp-value-0001-test-cp-value-0001-test-cp-value-0001";

    rmc_set("test-cp-key-0001", valinfo1, 0);
    rmc_get("test-cp-key-0001");

    // delete => add => get
    valinfo1.length = 56;
    valinfo1.value = "test-cp-value-0001-test-cp-value-0001-test-cp-value-0001";

    rmc_delete("test-cp-key-0002");
    rmc_add("test-cp-key-0002", valinfo1, 0);
    rmc_get("test-cp-key-0002");

    // replace => get
    valinfo1.length = 56;
    valinfo1.value = "test-cp-value-00a1-test-cp-value-00a1-test-cp-value-00a1";
    rmc_replace("test-cp-key-0002", valinfo1, 0);
    rmc_get("test-cp-key-0002");

    // append => get
    valinfo1.length = 56;
    valinfo1.value = "-test-cp-value-0aa1-test-cp-value-0aa1-test-cp-value-0aa1";
    rmc_append("test-cp-key-0002", valinfo1, 0);
    rmc_get("test-cp-key-0002");

    // prepend => get
    valinfo1.length = 56;
    valinfo1.value = "test-cp-value-paa1-test-cp-value-paa1-test-cp-value-paa1-";
    rmc_prepend("test-cp-key-0002", valinfo1, 0);
    rmc_get("test-cp-key-0002");

    // =============================
    // listcommand-1: insert => join
    rmc_delete("test-cp-key-0021");
    
    rmc_value_info valinfo5;

    valinfo5.length = 12;
    valinfo5.value = "list-0000001";
    rmc_alist_insert("test-cp-key-0021", 0, valinfo5);

    valinfo5.length = 12;
    valinfo5.value = "list-0000002";
    rmc_alist_insert("test-cp-key-0021", 1, valinfo5);

    valinfo5.length = 12;
    valinfo5.value = "list-0000003";
    rmc_alist_insert("test-cp-key-0021", 2, valinfo5);

    rmc_alist_join("test-cp-key-0021", "\t");

    // listcommand-2: include
    valinfo5.length = 12;
    valinfo5.value = "list-0000003";
    rmc_alist_include("test-cp-key-0021", valinfo5);

    // listcommand-3: index
    valinfo5.length = 12;
    valinfo5.value = "list-0000002";
    rmc_alist_index("test-cp-key-0021", valinfo5);

    valinfo5.length = 12;
    valinfo5.value = "list-0000001";
    rmc_alist_index("test-cp-key-0021", valinfo5);

    // listcommand-4: sized_insert => join
    rmc_delete("test-cp-key-0022");
    valinfo5.length = 12;
    valinfo5.value = "list-s000001";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000002";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000003";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000004";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000005";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000006";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000007";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000008";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000009";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    valinfo5.value = "list-s000010";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    rmc_alist_join("test-cp-key-0022", "\t");

    valinfo5.value = "list-s000011";
    rmc_alist_sized_insert("test-cp-key-0022", 10, valinfo5);

    rmc_alist_join("test-cp-key-0022", "\t");

    rmc_alist_first("test-cp-key-0022");
    rmc_alist_last("test-cp-key-0022");

    // listcommand-5: pop/push/shift => join
    rmc_delete("test-cp-key-0023");
    valinfo5.length = 12;
    valinfo5.value = "list-p000001";
    rmc_alist_push("test-cp-key-0023", valinfo5);
    
    valinfo5.value = "list-p000002";
    rmc_alist_push("test-cp-key-0023", valinfo5);

    valinfo5.value = "list-p000003";
    rmc_alist_push("test-cp-key-0023", valinfo5);

    rmc_alist_pop("test-cp-key-0023");
    rmc_alist_join("test-cp-key-0023", "\t");

    rmc_alist_shift("test-cp-key-0023");
    rmc_alist_join("test-cp-key-0023", "\t");

    rmc_alist_to_json("test-cp-key-0022");
    rmc_alist_tostr("test-cp-key-0022");

 }

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage : %s ${ip-address}_${port} ... \n", argv[0]);
        return (EXIT_FAILURE);
    }
    int hosts = argc -1;
    char *str_hosts[hosts];

    int i;
    for (i = 0; i < argc -1; i++)
    {
        str_hosts[i] = argv[i+1];
    }

    rmc_connect(hosts, str_hosts);
    //test_simple();
    test_complex();
    //test_serialize();
    rmc_disconnect();

    return (EXIT_SUCCESS);
}
