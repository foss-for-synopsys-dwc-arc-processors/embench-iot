#!/bin/sh

# find bdy/ -type f -executable -exec ./run_nsim.sh {} \;
${NSIM_HOME}/bin/nsimdrv -on nsim_isa_enable_timer_0 \
		       -on nsim_isa_enable_timer_1 \
		       -off invalid_instruction_interrupt \
		       -off memory_exception_interrupt \
		       -on nsim_download_elf_sections \
		       -p nsim_isa_family=av2em -p nsim_isa_core=3 \
		       -on nsim_isa_sat -p nsim_isa_code_density_option=2 \
		       -p nsim_isa_mpy_option=2 -p nsim_isa_bitscan_option=0 \
		       -on=nsim_print_stats_on_exit \
		        $1
