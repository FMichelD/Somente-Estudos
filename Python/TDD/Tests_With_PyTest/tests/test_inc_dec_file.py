import random
from inc_dec import inc_dec_file  # The code to test

def test_increment_positive_number():
    assert inc_dec_file.increment(3) == 4

def test_decrement_positive_number():
    assert inc_dec_file.decrement(3) == 2
    
def test_increment_negative_number():
    assert inc_dec_file.increment(-3) == -2

def test_decrement_negative_number():
    assert inc_dec_file.decrement(-3) == -4    
    
def test_decrement_for_random_values():
    
    for i in range(0, 1000, 1):
        rnNumber = random.randrange(-1000, 1000, 1)
        assert inc_dec_file.decrement(rnNumber) == rnNumber-1

def test_increment_for_random_values():    
    for i in range(0, 1000, 1):
        rnNumber = random.randrange(-1000, 1000, 1)
        assert inc_dec_file.increment(rnNumber) == rnNumber+1