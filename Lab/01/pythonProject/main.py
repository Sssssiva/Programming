from tkinter import *
import json
from tkinter.font import BOLD
import requests

def cli(event=None):
	try:
		response = requests.get("http://localhost:3000/raw").content.decode("utf8")
		forecast_j = json.loads(response)

		d.config(text=str(forecast_j["d"]))
		temperature.config(text=str(round(forecast_j["t"])) + "°C")
	except requests.exceptions.ConnectionError:
		pass



root = Tk()
root.bind("<Button-1>", cli)
root.title("Погода")
root.pack_propagate(0)



down = Frame(root, bg='gold', width=100, height=30)
up =    Frame(root, bg='gold', width=100, height=30)
mid = Frame(root, bg="#ffffff",  width=100, height=90)



down.pack(side=BOTTOM, fill=X)
up.pack(side=TOP, fill=X)
mid.pack(expand=True, fill=BOTH)



temperature = Label(mid, font=("Arial Bold", 46,BOLD), bg='#ffffff')
city = Label(up, font=("Arial Bold", 11,BOLD), text="Симферополь", bg="gold")
d = Label(up, font=("Arial Bold", 11), bg='gold')



temperature.pack(expand=True)
city.pack(pady=0)
d.pack(pady=0)


cli()
root.mainloop()

