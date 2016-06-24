#!/bin/bash

export LD_LIBRARY_PATH=/root/odp-bin/lib:/root/buildrump.sh/rump/lib
OFP_NETWRAP_ENV="-i 0 -f /root/ofp/scripts/ofp_netwrap.conf" LD_PRELOAD=libofp_netwrap_crt.so.0.0.0:libofp.so.1.0.0:libofp_netwrap_proc.so.0.0.0 sockperf server -i 192.168.78.12
