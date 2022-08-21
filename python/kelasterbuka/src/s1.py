import time

start_time=time.time()
print("Maulana Rezi Amirul Shidiq Rosadi")
# inline comment
"""
multiline comment
"""
a=10
print(a)
for i in range (1,1000):
    a = 10
print(time.time() - start_time, "seconds")

"""
-to run as intrepet
cd to src directory and type
python s1.py
-to compile for bytecode
python -m py_compile s1.py
-to run
cd to __pycache__ directory and type
python .\s1.cpython-310.pyc
"""