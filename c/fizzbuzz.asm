; FizzBuzz algorithm for Z80 Assembler

    ORG 8000

LIMIT = 100

start:
    exx
    push hl
    ld c, 1

_main:
    ld a,0
    ld (hit),a
    ld d,c
    ld e,3
    call div_d_e
    cp a, 0
    jr nz, nomod3
    ld a,1
    ld (hit),a
    ld de, fizz
    call print_de
nomod3:
    ld d,c
    ld e,5
    call div_d_e
    cp a,0
    jr nz, nomod5
    ld a,1
    ld (hit),a
    ld de, buzz
    call print_de
nomod5:
    ld a,(hit)
    cp 0
    jr nz, fizzbuzz

fizzbuzz:
    ld a, $0A       ; load \n newline char
    call $30
    inc c
    ld a,LIMIT
    cp c
    jr nz,_main

    pop hl
    exx
    ret

hit: 
    db 0
fizz:   
    db "Fizz"
buzz:   
    db "Buzz"   


div_d_e:
    xor a
    ld b,a

divloop:
    sla d
    rla
    cp e
    jr c, cont
    sub e
cont:
    inc d

    djnz divloop
    ret

print_de:
    ld b, 4
printloop:
    ld a, (de)
    call $30
    inc de
    djnz printloop
    ret

; modulo algo: http://chilliant.blogspot.com/2010/12/modulo-arithmetic-in-z80-assembler.html