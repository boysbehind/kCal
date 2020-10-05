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

def hello(str):
    return str

def update_herolist():
    # 响应
    response = urllib.request.urlopen("http://pvp.qq.com/web201605/js/herolist.json")

    # 列表-字典数据
    hero_json = json.loads(response.read()) # 接受响应，读取内容
    hero_num = len(hero_json)

    for hero in range(hero_num):
        url ="https://pvp.qq.com/web201605/herodetail/"+str(hero_json[hero]['ename'])+".shtml"
        a = urllib.request.urlopen(url)
        html = a.read()
        html = html.decode("gbk")
        value=""
        tips=""
        for i in range(len(html)):
            if (html[i]=="%" and html[i+1] == '"'):
                value=value+html[i-2]
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
    f.close()

# 创建文件夹
"""
save_dir = 'heroskin/'
if not os.path.exists(save_dir):
    os.mkdir(save_dir)

for i in range(hero_num):
    skin_names = hero_json[i]['skin_name'].split('|')

    for cnt in range(len(skin_names)):
        #文件名，有几个皮肤，就下载几个图片
        save_file_name = save_dir + str(hero_json[i]['ename']) + '-' + hero_json[i]['cname'] + '-' + skin_names[cnt] + '.jpg'
        # 图片url
        skin_url = 'http://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/'+str(hero_json[i]['ename'])+'/' +str(hero_json[i]['ename']) + '-bigskin-' + str(cnt+1) +'.jpg'

        if not os.path.exists(save_file_name):
            urllib.request.urlretrieve(skin_url, save_file_name)
"""
