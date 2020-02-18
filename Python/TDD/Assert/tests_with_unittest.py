import unittest
import random

def func(x):
    return x + 1

class MyTest(unittest.TestCase):
    def test_func_return(self):
        self.assertEqual(func(3), 4);
        
        for i in range(0, 100, 1):
            j = random.randrange(0, 100, 1)
            self.assertEqual(func(j), j + 1)
            

if __name__ == "__main__":
    tests = MyTest()
    tests.test_func_return()