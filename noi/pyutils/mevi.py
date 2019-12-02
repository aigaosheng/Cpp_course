#!/usr/bin/python3
# -*- coding: utf-8 -*-

from igraph import *
import matplotlib.pyplot as plt


with open('/home/gao/Work/Cpp_course/noi/tree/fenwickTree.txt') as fi:
    lns = list(map(lambda x: x.strip('\n'), fi.readlines()))
    #print(lns)
    nn = len(lns) - 1
    #g = Graph()
    #g.add_vertices(range(1, nn + 1))
    #layout = g.layout("tree")
    #plot(g, layout = layout)
    for ln in lns[1:]:
        nd = list(map(lambda x:(int(x[0]), int(x[1])), map(lambda x:x.split(':'), ln.split(','))))
        in_id, in_v = nd[0]#current input id, value
        g = Graph()
        g.add_vertex(0)
        for k in range(1, nn):
            g.add_vertices(k)
            g.add_edges([(0, k)])
        for bit_node, bit_v in nd[1:]:
            if in_id != bit_node:
                g.add_edges([(in_id, bit_node)])
        layout = g.layout_reingold_tilford()
        plot(g, layout = layout)#, opacity=0.1)
            #plx.show()

        #plt.show()
        #plt.savefig('t{}.png'.format(imgid))


