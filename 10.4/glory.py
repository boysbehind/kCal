# -*- coding: utf-8 -*-
"""
Created on Sun Oct  4 17:07:52 2020

@author: zhangyun
"""
import urllib.request
import json
import os
# 响应
response = urllib.request.urlopen("http://pvp.qq.com/web201605/js/herolist.json")

# 列表-字典数据
hero_json = json.loads(response.read()) # 接受响应，读取内容
hero_num = len(hero_json)

count = 1

save_dir = 'heroskin/'
save_file_name = save_dir + 'data.txt'
if not os.path.exists(save_dir):
    os.mkdir(save_dir)

if not os.path.exists(save_file_name):
    
for i in range(hero_num):
    print (count)
    print (hero_json[i]['ename'], hero_json[i]['cname'])
    count=count+1

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
