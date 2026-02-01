import ctypes
from tkinter import *

core = ctypes.CDLL("../smartlab.dll")

def calcul_force():
    f = core.force(10, 2)
    lbl.config(text=f"Force = {f} N")

root = Tk()
root.title("Module Physique")

Button(root, text="Calculer Force", command=calcul_force).pack()
lbl = Label(root)
lbl.pack()

root.mainloop()