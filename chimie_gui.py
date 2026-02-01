import ctypes
from tkinter import *

core = ctypes.CDLL("../smartlab.dll")

def calcul_ph():
    p = core.ph(0.0001)
    lbl.config(text=f"pH = {p}")

root = Tk()
root.title("Module Chimie")

Button(root, text="Calcul pH", command=calcul_ph).pack()
lbl = Label(root)
lbl.pack()

root.mainloop()