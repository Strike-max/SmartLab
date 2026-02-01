from tkinter import *
import ctypes

core = ctypes.CDLL("../smartlab.dll")

root = Tk()
root.title("Module Informatique")

Label(root, text="Algorithmes de base").pack(pady=10)

root.mainloop()