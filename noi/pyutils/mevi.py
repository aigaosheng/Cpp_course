#!/usr/bin/python3
# -*- coding: utf-8 -*-

from igraph import *
import matplotlib.pyplot as plt


with open('/home/gao/Work/Cpp_course/noi/tree/fenwickTree.txt') as fi:
    lns = map(lambda x: x.strip('\n'), fi.readlines())
    g = Graph()
    g.add_vertices(range(1, len(lns) + 1))
    for imgid, ln in enumerate(fi):
        nd = ln.strip('\n').split('img')
        in_id, in_v = nd[0].split(':')#current input id, value
        for i_v in nd[1].split('*'):
            #print(i_v)
            if len(i_v) == 0:
                continue
            n_v = i_v.split(',')
            bit = n_v[0].split(':')
            #ed = map(lambda x:(int(x[0],int(x[1]))),map(lambda x:x.split(':'), n_v[1:]))
            ed = filter(lambda x:len(x)>0, map(lambda x:x.split(':'), n_v[1:]))
            ed = map(lambda x: (int(x[0]), int(x[1])), ed)
            ed = filter(lambda x: len(x)==2, ed)
            #print(list(ed))

            g.add_edges(ed)
            layout = g.layout("kk")
            plot(g, layout = layout)

        #plt.show()
        #plt.savefig('t{}.png'.format(imgid))


