.equ LED_PIN, 13   ; Define LED pin number

.global main
main:
    ldi r16, 0xFF   ; Set port D as output
    out DDRB, r16

loop:
    ldi r16, (1 << LED_PIN)  ; Set bit corresponding to LED_PIN
    out PORTB, r16    ; Turn on LED
    rjmp loop         ; Loop infinitely

