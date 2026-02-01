import tkinter as tk
from tkinter import messagebox
import subprocess
import os
import subprocess
subprocess.Popen(["smartlab.exe"])

# Chemin des modules
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

def open_module(module_file, module_name):
    try:
        subprocess.Popen(["python", os.path.join(BASE_DIR, module_file)])
    except:
        messagebox.showerror("Erreur", f"Impossible d'ouvrir le module {module_name}")

# ----- Fenêtre principale -----
root = tk.Tk()
root.title("SmartLab Education v2.0")
root.geometry("1000x650")
root.configure(bg="#f8f9fa")

# ----- Sidebar -----
sidebar = tk.Frame(root, bg="#212529", width=220)
sidebar.pack(side="left", fill="y")

title = tk.Label(
    sidebar,
    text="SMARTLAB",
    fg="white",
    bg="#212529",
    font=("Segoe UI", 18, "bold")
)
title.pack(pady=30)

# Style des boutons
btn_style = {
    "font": ("Segoe UI", 11, "bold"),
    "fg": "white",
    "bg": "#0d6efd",
    "activebackground": "#0b5ed7",
    "bd": 0,
    "height": 2
}

tk.Button(sidebar, text="📘 Maths", command=lambda: open_module("maths_gui.py", "Maths"), **btn_style).pack(fill="x", padx=20, pady=8)
tk.Button(sidebar, text="💻 Informatique", command=lambda: open_module("info_gui.py", "Info"), **btn_style).pack(fill="x", padx=20, pady=8)
tk.Button(sidebar, text="⚛️ Physique", command=lambda: open_module("physique_gui.py", "Physique"), **btn_style).pack(fill="x", padx=20, pady=8)
tk.Button(sidebar, text="🧪 Chimie", command=lambda: open_module("chimie_gui.py", "Chimie"), **btn_style).pack(fill="x", padx=20, pady=8)

tk.Button(
    sidebar,
    text="❌ Quitter",
    command=root.quit,
    bg="#dc3545",
    fg="white",
    font=("Segoe UI", 11, "bold"),
    bd=0,
    height=2
).pack(fill="x", padx=20, pady=30)

# ----- Header -----
header = tk.Frame(root, bg="#343a40", height=60)
header.pack(side="top", fill="x")

header_label = tk.Label(
    header,
    text="TABLEAU DE BORD — SMARTLAB EDUCATION",
    bg="#343a40",
    fg="white",
    font=("Segoe UI", 14, "bold")
)
header_label.pack(pady=15)

# ----- Zone principale -----
main_area = tk.Frame(root, bg="white")
main_area.pack(expand=True, fill="both", padx=20, pady=20)

welcome = tk.Label(
    main_area,
    text="Bienvenue sur SmartLab 🎓\n\nSélectionnez un module à gauche.",
    bg="white",
    fg="#212529",
    font=("Segoe UI", 14)
)
welcome.pack(expand=True)

root.mainloop()