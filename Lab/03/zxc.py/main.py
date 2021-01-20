from tkinter import *
from PIL import Image, ImageTk
import random


def add_three_defolt_balls():
    global our_lable
    global prompt_1, prompt_2, prompt_3
    global defeat
    global defolt_balls_counter
    global defolt_balls
    bool = True
    while (bool):
        tile_1,tile_2, tile_3   = random.randint(0, 80), random.randint(0, 80), random.randint(0, 80)
        if (our_lable[tile_1].used == False) and (our_lable[tile_2].used == False) and (
                our_lable[tile_3].used == False) and (tile_1 != tile_2) and (
                tile_1 != tile_3) and (tile_2 != tile_3):
            bool = False
    x1, y1, x2, y2, x3, y3 = our_lable[tile_1].row, our_lable[tile_1].col, our_lable[tile_2].row, our_lable[tile_2].col, \
                             our_lable[tile_3].row, our_lable[tile_3].col

    our_lable[tile_1] = Label(root, image=defolt_balls[prompt_1], borderwidth=0)
    our_lable[tile_2] = Label(root, image=defolt_balls[prompt_2], borderwidth=0)
    our_lable[tile_3] = Label(root, image=defolt_balls[prompt_3], borderwidth=0)

    our_lable[tile_1].color = prompt_1
    our_lable[tile_2].color = prompt_2
    our_lable[tile_3].color = prompt_3

    our_lable[tile_1].row = x1
    our_lable[tile_2].row = x2
    our_lable[tile_3].row = x3

    our_lable[tile_1].col = y1
    our_lable[tile_2].col = y2
    our_lable[tile_3].col = y3

    our_lable[tile_1].tile = tile_1
    our_lable[tile_2].tile = tile_2
    our_lable[tile_3].tile = tile_3

    our_lable[tile_1].used = True
    our_lable[tile_2].used = True
    our_lable[tile_3].used = True

    our_lable[tile_1].bind("<Button-1>", Used_ball)
    our_lable[tile_2].bind("<Button-1>", Used_ball)
    our_lable[tile_3].bind("<Button-1>", Used_ball)

    our_lable[tile_1].place(x=our_lable[tile_1].row * 70 + 10, y=our_lable[tile_1].col * 70 + 10)
    our_lable[tile_2].place(x=our_lable[tile_2].row * 70 + 10, y=our_lable[tile_2].col * 70 + 10)
    our_lable[tile_3].place(x=our_lable[tile_3].row * 70 + 10, y=our_lable[tile_3].col * 70 + 10)

    prompt_1, prompt_2, prompt_3 = random.randint(0, 6), random.randint(0, 6), random.randint(0, 6)

    prompt_1_lbl = Label(root, image=defolt_balls[prompt_1], borderwidth=0)
    prompt_1_lbl.place(x=650, y=290)

    prompt_2_lbl = Label(root, image=defolt_balls[prompt_2], borderwidth=0)
    prompt_2_lbl.place(x=730, y=290)

    prompt_3_lbl = Label(root, image=defolt_balls[prompt_3], borderwidth=0)
    prompt_3_lbl.place(x=810, y=290)

    Del_horizont()
    Del_verticale()
    Del_giagonale(9)
    Del_giagonale_back(70)
    defolt_balls_counter = 0

    for i in range(81):
        if our_lable[i].used == True:
            defolt_balls_counter += 1
            if defolt_balls_counter > 78:
                defeat = Label(root, text="Поражение", font=("Arial", 26), bg="#414141", fg="white")
                defeat.place(x=650, y=600)


def Del_giagonale(k):
    global our_lable
    global awards
    defolt_balls_equal_color = []
    i = k
    for i in range(i, 81, 10):
        if (i < 18):
            k = i
            defolt_balls_equal_color.append(our_lable[i - 10])
        if len(defolt_balls_equal_color) == 5 and defolt_balls_equal_color[0].color != -1:
            for j in range(len(defolt_balls_equal_color)):
                defolt_balls_equal_color[j].config(image=defolt_image)
                defolt_balls_equal_color[j].color = -1
                defolt_balls_equal_color[j].used = False
                awards += 2
        if our_lable[i].color == our_lable[i - 10].color:
            defolt_balls_equal_color.append(our_lable[i])
        else:
            if len(defolt_balls_equal_color) == 5 and defolt_balls_equal_color[0].color != -1:
                for j in range(len(defolt_balls_equal_color)):
                    defolt_balls_equal_color[j].config(image=defolt_image)
                    defolt_balls_equal_color[j].color = -1
                    defolt_balls_equal_color[j].used = False
                    awards += 2
            defolt_balls_equal_color.clear()
            defolt_balls_equal_color.append(our_lable[i])
        if (i > 71) and (len(defolt_balls_equal_color) == 5) and defolt_balls_equal_color[0].color != -1:
            for j in range(len(defolt_balls_equal_color)):
                defolt_balls_equal_color[j].config(image=defolt_image)
                defolt_balls_equal_color[j].color = -1
                defolt_balls_equal_color[j].used = False
                awards += 2
            defolt_balls_equal_color.clear()
    if (k < 81):
        Del_giagonale(k + 1)
    remake_awards()


def Del_giagonale_back(k):
    global awards
    global our_lable
    defolt_balls_equal_color = []
    i = k
    for i in range(i, -1, -8):
        if (i > 62 and i != 63):
            k = i
            defolt_balls_equal_color.append(our_lable[i + 8])
        if our_lable[i].color == our_lable[i + 8].color:
            defolt_balls_equal_color.append(our_lable[i])
        else:
            if len(defolt_balls_equal_color) == 5 and defolt_balls_equal_color[0].color != -1:
                for j in range(len(defolt_balls_equal_color)):
                    defolt_balls_equal_color[j].config(image=defolt_image)
                    defolt_balls_equal_color[j].color = -1
                    defolt_balls_equal_color[j].used = False
                    awards += 2
            defolt_balls_equal_color.clear()
            defolt_balls_equal_color.append(our_lable[i])
        if (i < 9) and (len(defolt_balls_equal_color) == 5) and defolt_balls_equal_color[0].color != -1:
            for j in range(len(defolt_balls_equal_color)):
                defolt_balls_equal_color[j].config(image=defolt_image)
                defolt_balls_equal_color[j].color = -1
                defolt_balls_equal_color[j].used = False
                awards += 2
            defolt_balls_equal_color.clear()
        if (i % 9 == 8) and (len(defolt_balls_equal_color) == 5) and defolt_balls_equal_color[0].color != -1:
            for j in range(len(defolt_balls_equal_color)):
                defolt_balls_equal_color[j].config(image=defolt_image)
                defolt_balls_equal_color[j].color = -1
                defolt_balls_equal_color[j].used = False
                awards += 2
            defolt_balls_equal_color.clear()
        remake_awards()
        if (i % 9 == 8):
            break
    if (k > -1):
        Del_giagonale_back(k - 1)


def Del_verticale():
    global our_lable
    global awards
    in_matrix = []
    counter = 0
    for i in range(9):
        temp = []
        for j in range(9):
            temp.append(our_lable[counter])
            counter += 1
        in_matrix.append(temp)
    defolt_balls_equal_color = []
    for row in range(9):
        defolt_balls_equal_color.append(in_matrix[0][row])
        for col in range(1, 9):
            if len(defolt_balls_equal_color) == 5 and defolt_balls_equal_color[0].color != -1:
                for j in range(len(defolt_balls_equal_color)):
                    defolt_balls_equal_color[j].config(image=defolt_image)
                    defolt_balls_equal_color[j].color = -1
                    defolt_balls_equal_color[j].used = False
                    awards += 2
            if (in_matrix[col][row].color == in_matrix[col - 1][row].color):
                defolt_balls_equal_color.append(in_matrix[col][row])
            else:
                if len(defolt_balls_equal_color) == 5 and defolt_balls_equal_color[0].color != -1:
                    for j in range(len(defolt_balls_equal_color)):
                        defolt_balls_equal_color[j].config(image=defolt_image)
                        defolt_balls_equal_color[j].color = -1
                        defolt_balls_equal_color[j].used = False
                        awards += 2
                defolt_balls_equal_color.clear()
                defolt_balls_equal_color.append(in_matrix[col][row])
            if (col == 8) and (len(defolt_balls_equal_color) == 5) and defolt_balls_equal_color[0].color != -1:
                for j in range(len(defolt_balls_equal_color)):
                    defolt_balls_equal_color[j].config(image=defolt_image)
                    defolt_balls_equal_color[j].color = -1
                    defolt_balls_equal_color[j].used = False
                    awards += 2
                defolt_balls_equal_color.clear()
            if (col == 8):
                defolt_balls_equal_color.clear()
    remake_awards()


def beginning():
    global prompt_1, prompt_2, prompt_3
    global our_lable
    global awards
    awards = 0
    prompt_1, prompt_2, prompt_3 = random.randint(0, 6), random.randint(0, 6), random.randint(0, 6)
    our_lable = []
    remember = 0
    for row in range(9):
        for col in range(9):
            lbl = Label(root, image=defolt_image, borderwidth=0)
            lbl.row = col
            lbl.col = row
            lbl.tile = remember
            lbl.color = -1
            lbl.used = False
            lbl.bind("<Button-1>", Used_ball)
            lbl.place(x=(col * 70) + 10, y=(row * 70) + 10)
            our_lable.append(lbl)
            remember += 1


def Del_horizont():
    global our_lable
    global awards
    defolt_balls_equal_color = []
    defolt_balls_equal_color.append(our_lable[0])
    for i in range(1, 81):
        if (i % 9 == 0) and (i != 0):
            if len(defolt_balls_equal_color) == 5 and defolt_balls_equal_color[0].color != -1:
                for j in range(len(defolt_balls_equal_color)):
                    defolt_balls_equal_color[j].config(image=defolt_image)
                    defolt_balls_equal_color[j].color = -1
                    defolt_balls_equal_color[j].used = False
                    awards += 2
            defolt_balls_equal_color.clear()
            defolt_balls_equal_color.append(our_lable[i])
        if len(defolt_balls_equal_color) == 5 and defolt_balls_equal_color[0].color != -1:
            for j in range(len(defolt_balls_equal_color)):
                defolt_balls_equal_color[j].config(image=defolt_image)
                defolt_balls_equal_color[j].color = -1
                defolt_balls_equal_color[j].used = False
                awards += 2
        if our_lable[i].color == our_lable[i - 1].color:
            defolt_balls_equal_color.append(our_lable[i])
        else:
            if len(defolt_balls_equal_color) == 5 and defolt_balls_equal_color[0].color != -1:
                for j in range(len(defolt_balls_equal_color)):
                    defolt_balls_equal_color[j].config(image=defolt_image)
                    defolt_balls_equal_color[j].color = -1
                    defolt_balls_equal_color[j].used = False
                    awards += 2
            defolt_balls_equal_color.clear()
            defolt_balls_equal_color.append(our_lable[i])
        if (i == 80) and (len(defolt_balls_equal_color) == 5) and defolt_balls_equal_color[0].color != -1:
            for j in range(len(defolt_balls_equal_color)):
                defolt_balls_equal_color[j].config(image=defolt_image)
                defolt_balls_equal_color[j].color = -1
                defolt_balls_equal_color[j].used = False
                awards += 2
            defolt_balls_equal_color.clear()
    remake_awards()


use = False


def rebeginning(event):
    global use
    global our_lable
    global defeat
    global defolt_image
    defeat = Label(root, text='', font=('Arial', 40), bg="#414141")
    defeat.place(x=650, y=600)
    our_lable.clear()
    beginning()
    add_three_defolt_balls()
    use = False


def Used_ball(event):
    global use, defolt_image, our_lable, remember_num, use_color, x1, y1, in_matrix, used_defolt_balls, defolt_balls

    if use == False:
        if event.widget.color != -1:
            event.widget.config(image=used_defolt_balls[event.widget.color])
            remember_num = event.widget.tile
            use_color = event.widget.color
            x1 = event.widget.row
            y1 = event.widget.col
            use = True
    if use == True:
        if event.widget.color == -1:
            # if voln(x1,y1,event.widget.row,event.widget.col, in_matrix):
            event.widget.used = True
            our_lable[remember_num].used = False
            event.widget.config(image=defolt_balls[use_color])
            event.widget.color = use_color
            our_lable[remember_num].config(image=defolt_image)
            our_lable[remember_num].color = -1
            use = False
            add_three_defolt_balls()
        else:
            if event.widget.tile != remember_num:
                our_lable[remember_num].config(image=defolt_balls[use_color])
                event.widget.config(image=used_defolt_balls[event.widget.color])
                remember_num = event.widget.tile
                use_color = event.widget.color


def click(event):
    global defolt_balls_counter
    if defolt_balls_counter > 78:
        return ""
    add_three_defolt_balls()


def remake_awards():
    global award_label, awards
    award_label.config(text=awards)


root = Tk()
root.configure(bg="#414141")
root.geometry("900x646")

tileset = Image.open("cell-bgr.png")
defolt_image = ImageTk.PhotoImage(tileset.crop((1, 0, 67, 66)))
defolt_image_use = ImageTk.PhotoImage(tileset.crop((1, 69, 67, 135)))

game_label_name = Label(root, text="Ивановики", font=("Arial", 26), bg="#414141", fg="white")
game_label_name.place(x=650, y=25)
lbl_award_label = Label(root, text="Счёт: ", font=("Arial", 26), bg="#414141", fg="white")
lbl_award_label.place(x=650, y=90)
prompt_label = Label(root, text="Подсказка: ", font=("Arial", 16), bg="#414141", fg="white")
prompt_label.place(x=650, y=250)

awards = 0
award_label = Label(root, text=awards, font=("Arial", 26), bg="#414141", fg="white")
award_label.place(x=750, y=90)

used_defolt_balls = []
defolt_balls = []

bgr_blue = Image.open("cell-bgr.png").convert('RGBA')
ball_blue = Image.open("ball-blue.png").convert('RGBA')
bgr_blue.paste(ball_blue, (6, 5), ball_blue)
blue = ImageTk.PhotoImage(bgr_blue.crop((1, 0, 67, 66)))

defolt_balls.append(blue)

bgr_aqua = Image.open("cell-bgr.png").convert('RGBA')
ball_aqua = Image.open("ball-aqua.png").convert('RGBA')
bgr_aqua.paste(ball_aqua, (6, 5), ball_aqua)
aqua = ImageTk.PhotoImage(bgr_aqua.crop((1, 0, 67, 66)))

defolt_balls.append(aqua)

bgr_green = Image.open("cell-bgr.png").convert('RGBA')
ball_green = Image.open("ball-green.png").convert('RGBA')
bgr_green.paste(ball_green, (6, 5), ball_green)
green = ImageTk.PhotoImage(bgr_green.crop((1, 0, 67, 66)))

defolt_balls.append(green)

bgr_pink = Image.open("cell-bgr.png").convert('RGBA')
ball_pink = Image.open("ball-pink.png").convert('RGBA')
bgr_pink.paste(ball_pink, (6, 5), ball_pink)
pink = ImageTk.PhotoImage(bgr_pink.crop((1, 0, 67, 66)))

defolt_balls.append(pink)

bgr_red = Image.open("cell-bgr.png").convert('RGBA')
ball_red = Image.open("ball-red.png").convert('RGBA')
bgr_red.paste(ball_red, (6, 5), ball_red)
red = ImageTk.PhotoImage(bgr_red.crop((1, 0, 67, 66)))

defolt_balls.append(red)

violet = Image.open("cell-bgr.png").convert('RGBA')
ball_violet = Image.open("ball-violet.png").convert('RGBA')
violet.paste(ball_violet, (6, 5), ball_violet)
img_violet = ImageTk.PhotoImage(violet.crop((1, 0, 67, 66)))

defolt_balls.append(img_violet)

yellow = Image.open("cell-bgr.png").convert('RGBA')
ball_yellow = Image.open("ball-yellow.png").convert('RGBA')
yellow.paste(ball_yellow, (6, 5), ball_yellow)
img_yellow = ImageTk.PhotoImage(yellow.crop((1, 0, 67, 66)))

defolt_balls.append(img_yellow)

bgr_blue_use = Image.open("cell-bgr.png").convert('RGBA')
ball_blue_use = Image.open("ball-blue.png").convert('RGBA')
bgr_blue_use.paste(ball_blue_use, (6, 74), ball_blue_use)
blue_use = ImageTk.PhotoImage(bgr_blue_use.crop((1, 69, 67, 135)))

used_defolt_balls.append(blue_use)

bgr_aqua_use = Image.open("cell-bgr.png").convert('RGBA')
ball_aqua_use = Image.open("ball-aqua.png").convert('RGBA')
bgr_aqua_use.paste(ball_aqua_use, (6, 74), ball_aqua_use)
aqua_use = ImageTk.PhotoImage(bgr_aqua_use.crop((1, 69, 67, 135)))
used_defolt_balls.append(aqua_use)

bgr_green_use = Image.open("cell-bgr.png").convert('RGBA')
ball_green_use = Image.open("ball-green.png").convert('RGBA')
bgr_green_use.paste(ball_green_use, (6, 74), ball_green_use)
green_use = ImageTk.PhotoImage(bgr_green_use.crop((1, 69, 67, 135)))

used_defolt_balls.append(green_use)

bgr_pink_use = Image.open("cell-bgr.png").convert('RGBA')
ball_pink_use = Image.open("ball-pink.png").convert('RGBA')
bgr_pink_use.paste(ball_pink_use, (6, 74), ball_pink_use)
pink_use = ImageTk.PhotoImage(bgr_pink_use.crop((1, 69, 67, 135)))

used_defolt_balls.append(pink_use)

bgr_red_use = Image.open("cell-bgr.png").convert('RGBA')
ball_red_use = Image.open("ball-red.png").convert('RGBA')
bgr_red_use.paste(ball_red_use, (6, 74), ball_red_use)
red_use = ImageTk.PhotoImage(bgr_red_use.crop((1, 69, 67, 135)))

used_defolt_balls.append(red_use)

violet_use = Image.open("cell-bgr.png").convert('RGBA')
ball_violet_use = Image.open("ball-violet.png").convert('RGBA')
violet_use.paste(ball_violet_use, (6, 74), ball_violet_use)
img_violet_use = ImageTk.PhotoImage(violet_use.crop((1, 69, 67, 135)))

used_defolt_balls.append(img_violet_use)

yellow_use = Image.open("cell-bgr.png").convert('RGBA')
ball_yellow_use = Image.open("ball-yellow.png").convert('RGBA')
yellow_use.paste(ball_yellow_use, (6, 74), ball_yellow_use)
img_yellow_use = ImageTk.PhotoImage(yellow_use.crop((1, 69, 67, 135)))

used_defolt_balls.append(img_yellow_use)

lbl_new_game = Label(root, text="Новая игра", font=("Arial", 26), bg="#414141", fg="white")
lbl_new_game.bind("<Button-1>", rebeginning)
lbl_new_game.place(x=650, y=370)

lbl_click = Label(root, text="Сделать ход", font=("Arial", 24), bg="#414141", fg="white")
lbl_click.bind("<Button-1>", click)
lbl_click.place(x=650, y=440)

beginning()
add_three_defolt_balls()
root.mainloop()