import ctypes
from tkinter import *

core = ctypes.CDLL("../smartlab.dll")

def calcul():
    res = core.addition(5, 3)
    result.config(text=f"Résultat : {res}")

root = Tk()
root.title("Module Maths")

Button(root, text="Addition 5 + 3", command=calcul).pack(pady=10)
result = Label(root, text="")
result.pack()

root.mainloop()