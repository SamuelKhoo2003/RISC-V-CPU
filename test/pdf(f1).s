.text
main:
    JAL     ra, init            # jump to init, ra and save position to ra
forever:
    JAL     ra, build
    JAL     forever

init:                           # initialise light
    LI      t0, 0xFF            # temp register
    RET

build:                          # function to build prob dist func (pdf)
    LI      a0, 0               # begin with all lights off
    LI      t1, 0   
_loop2:                         # repeat till all lights on
    SLLI    t1, t1, 1 
    ADDI    t1, t1, 1
    ADDI    a0, t1, 0
    BNE     a0, t0, _loop2      # until all lights are on
    RET

