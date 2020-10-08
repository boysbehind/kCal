#!/usr/bin/env python
# -*- coding: utf-8 -*-
# -*- coding: utf-8 -*-
"""
Created on Sun Oct  4 17:07:52 2020

@author: zhangyun
"""
import urllib.request
import json
import os

def get_json():
    CWD=os.getcwd()
    FILE = open(CWD+"/herolist/herolist.json", 'r', encoding = "utf-8")
    HERO_JSON = json.loads(FILE.read())
    FILE.close()
    return HERO_JSON

def hello(str):
    return str

#下载/更新英雄列表，返回是否成功
def update_herolist(done):
    done = False
    # 响应
    response = urllib.request.urlopen("http://pvp.qq.com/web201605/js/herolist.json")

    # 列表-字典数据
    hero_json = json.loads(response.read()) # 接受响应，读取内容
    hero_num = len(hero_json)

    for i in range(hero_num):
        #马超数据缺失
        if hero_json[i]["cname"] == "马超":
            hero_json[i]["skin_name"] = "冷晖之枪|幸存者|神威"

    for hero in range(hero_num):
        url ="https://pvp.qq.com/web201605/herodetail/"+str(hero_json[hero]['ename'])+".shtml"
        a = urllib.request.urlopen(url)
        html = a.read()
        html = html.decode("gbk")
        value=""
        tips=""
        for i in range(len(html)):
            #查找英雄属性
            if (html[i]=="%" and html[i+1] == '"'):
                value=value+html[i-2]
            #查找铭文建议
            if (html[i]=="T" and html[i+1]=="i" and html[i+2]=="p" and html[i-8]=="g"):
                c=i+4
                while (not html[c]=="<"):
                    c=c+1
                    if html[c]=="<":break
                    tips=tips+html[c]
        hero_json[hero]['sugg_tips']=tips
        hero_json[hero]['ability']=value

    info_json = json.dumps(hero_json, ensure_ascii=False, indent=4)

    save_dir = os.getcwd()+'/herolist/'
    if not os.path.exists(save_dir):
        os.mkdir(save_dir)

    save_file_name = save_dir + '/herolist.json'

    with open(save_file_name, 'w', encoding = 'utf-8') as f:
        f.write(info_json)
        done = True
    f.close()
    return done


#下载或更新皮肤文件，返回是否成功
def update_herogif(done):
    done = False
    save_dir = os.getcwd()+'/heroskin/'
    if not os.path.exists(save_dir):
        os.mkdir(save_dir)

    response = urllib.request.urlopen("http://pvp.qq.com/web201605/js/herolist.json")

    # 列表-字典数据
    hero_json = json.loads(response.read()) # 接受响应，读取内容
    hero_num = len(hero_json)

    for i in range(hero_num):
        #马超数据缺失
        if hero_json[i]["cname"] == "马超":
            hero_json[i]["skin_name"] = "冷晖之枪|幸存者|神威"
        skin_names = hero_json[i]["skin_name"].split('|')

        for cnt in range(len(skin_names)):
            #文件名，有几个皮肤，就下载几个图片
            save_file_name = save_dir + str(hero_json[i]['ename']) + '-' + hero_json[i]['cname'] + '-' + skin_names[cnt] + '.jpg'
            # 图片url
            skin_url = 'http://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/'+str(hero_json[i]['ename'])+'/' +str(hero_json[i]['ename']) + '-bigskin-' + str(cnt+1) +'.jpg'

            if not os.path.exists(save_file_name):
                urllib.request.urlretrieve(skin_url, save_file_name)

    if os.path.exists(save_file_name): done=True
    return done

def hero_num():
    HERO_JSON = get_json()
    HERO_NUM = len(HERO_JSON)
    return 102

def hero_ename(count):
    HERO_JSON = get_json()
    HERO_NUM = len(HERO_JSON)
    for cnt in range (HERO_NUM):
        if cnt==count:
            return HERO_JSON[cnt]["ename"]
    return "error"

def hero_type(count):
    HERO_JSON = get_json()
    HERO_NUM = len(HERO_JSON)
    for cnt in range (HERO_NUM):
        if cnt==count:
            return str(HERO_JSON[cnt]["hero_type"])
    return "error"

def hero_title(count):
    HERO_JSON = get_json()
    HERO_NUM = len(HERO_JSON)
    for cnt in range (HERO_NUM):
        if cnt == count:
            return HERO_JSON[cnt]["title"]
    return "error"

def is_newhero(count):
    HERO_JSON = get_json()
    HERO_NUM = len(HERO_JSON)
    for cnt in range (HERO_NUM):
        if HERO_JSON[cnt]["new_type"]==1:
            return "1"
    return "0"

def sugg_tips(count):
    HERO_JSON = get_json()
    HERO_NUM = len(HERO_JSON)
    for cnt in range (HERO_NUM):
        if cnt == count:
            return HERO_JSON[cnt]["sugg_tips"]
    return "error"

def skin_name(count):
    HERO_JSON = get_json()
    HERO_NUM = len(HERO_JSON)
    for cnt in range (HERO_NUM):
        if cnt == count:
            return HERO_JSON[cnt]["skin_name"]
    return "error"

def hero_ability(count):
    HERO_JSON = get_json()
    HERO_NUM = len(HERO_JSON)
    for cnt in range (HERO_NUM):
        if cnt == count:
            return HERO_JSON[cnt]["ability"]
