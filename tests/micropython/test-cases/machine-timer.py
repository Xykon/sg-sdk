# test machine.Timer

try:
    import utime, umachine as machine

    machine.Timer
except:
    print("SKIP")
    raise SystemExit

# create and deinit
t = machine.Timer(1, freq=1)
t.deinit()

# deinit again
t.deinit()

# create 2 and deinit
t = machine.Timer(1, freq=1)
t2 = machine.Timer(2, freq=1)
t.deinit()
t2.deinit()

# create 2 and deinit in different order
t = machine.Timer(1, freq=1)
t2 = machine.Timer(2, freq=1)
t2.deinit()
t.deinit()

# create one-shot timer with callback and wait for it to print (should be just once)
t = machine.Timer(1, period=1, mode=machine.Timer.ONE_SHOT, callback=lambda t: print("one-shot"))
utime.sleep_ms(5)
t.deinit()

# create periodic timer with callback and wait for it to print
t = machine.Timer(1, period=4, mode=machine.Timer.PERIODIC, callback=lambda t: print("periodic"))
utime.sleep_ms(14)
t.deinit()
