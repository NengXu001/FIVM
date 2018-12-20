#!/bin/bash

make bin/full_join/housing/Factorized_Housing_DF-INCR_ALL_GENERATED_1000
make bin/full_join/retailer/Factorized_Retailer_DF-INCR_ALL_GENERATED_1000
make bin/full_join/retailer/Factorized_Retailer_DF-INCR_INVENTORY_GENERATED_1000

make bin/full_join/housing/Relational_Housing_DF-INCR_ALL_GENERATED_1000
make bin/full_join/retailer/Relational_Retailer_DF-INCR_ALL_GENERATED_1000
make bin/full_join/retailer/Relational_Retailer_DF-INCR_INVENTORY_GENERATED_1000

make bin/cofactor/housing/Cofactor_Housing_DF-INCR_ALL_GENERATED_1000
make bin/cofactor/retailer/Cofactor_Retailer_DF-INCR_ALL_GENERATED_1000
make bin/cofactor/retailer/Cofactor_Retailer_DF-INCR_INVENTORY_GENERATED_1000

make bin/sum/tpch/TPCH1_DF-INCR_ALL_GENERATED_1000
make bin/sum/tpch/TPCH3_DF-INCR_ALL_GENERATED_1000
make bin/sum/tpch/TPCH6_DF-INCR_ALL_GENERATED_1000
make bin/sum/tpch/TPCH10_DF-INCR_ALL_GENERATED_1000
make bin/sum/tpch/TPCH12_DF-INCR_ALL_GENERATED_1000
make bin/sum/tpch/TPCH14_DF-INCR_ALL_GENERATED_1000

make bin/full_join/housing/Factorized_Housing_DF-INCR_ALL_GENERATED_SINGLE
make bin/full_join/retailer/Factorized_Retailer_DF-INCR_ALL_GENERATED_SINGLE
make bin/full_join/retailer/Factorized_Retailer_DF-INCR_INVENTORY_GENERATED_SINGLE

make bin/full_join/housing/Relational_Housing_DF-INCR_ALL_GENERATED_SINGLE
make bin/full_join/retailer/Relational_Retailer_DF-INCR_ALL_GENERATED_SINGLE
make bin/full_join/retailer/Relational_Retailer_DF-INCR_INVENTORY_GENERATED_SINGLE

make bin/cofactor/housing/Cofactor_Housing_DF-INCR_ALL_GENERATED_SINGLE
make bin/cofactor/retailer/Cofactor_Retailer_DF-INCR_ALL_GENERATED_SINGLE
make bin/cofactor/retailer/Cofactor_Retailer_DF-INCR_INVENTORY_GENERATED_SINGLE

make bin/sum/tpch/TPCH1_DF-INCR_ALL_GENERATED_SINGLE
make bin/sum/tpch/TPCH3_DF-INCR_ALL_GENERATED_SINGLE
make bin/sum/tpch/TPCH6_DF-INCR_ALL_GENERATED_SINGLE
make bin/sum/tpch/TPCH10_DF-INCR_ALL_GENERATED_SINGLE
make bin/sum/tpch/TPCH12_DF-INCR_ALL_GENERATED_SINGLE
make bin/sum/tpch/TPCH14_DF-INCR_ALL_GENERATED_SINGLE