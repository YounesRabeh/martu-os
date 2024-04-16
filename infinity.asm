.equ LED_PIN, 13   ; Define LED pin number

.global main
main:
    ; Initialize stack pointer
    ldi r16, low(RAMEND)
    out SPL, r16
    ldi r16, high(RAMEND)
    out SPH, r16
    
    ; Initialize port D as output
    ldi r16, 0xFF   ; Set port B as output
    out DDRB, r16

loop:
    ; Turn on LED
    ldi r16, (1 << LED_PIN)  ; Set bit corresponding to LED_PIN
    out PORTB, r16    ; Turn on LED
    
    ; Delay
    ldi r20, 0xFF
    ldi r21, 0xFF
delay_loop:
    dec r21
    brne delay_loop
    dec r20
    brne delay_loop
    
    ; Turn off LED
    ldi r16, (0 << LED_PIN)  ; Clear bit corresponding to LED_PIN
    out PORTB, r16    ; Turn off LED
    
    ; Delay
    ldi r20, 0xFF
    ldi r21, 0xFF
delay_loop_off:
    dec r21
    brne delay_loop_off
    dec r20
    brne delay_loop_off
    
    rjmp loop         ; Loop infinitely
