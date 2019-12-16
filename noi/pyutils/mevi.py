#!/usr/bin/python3
# -*- coding: utf-8 -*-

import pygraphviz as pgv 
import matplotlib.pyplot as plt


with open('/home/gao/Work/Cpp_course/noi/tree/fenwickTree.txt') as fi:
    lns = list(map(lambda x: x.strip('\n'), fi.readlines()))
    #print(lns)
    nn = len(lns) - 1
    g = pgv.AGraph(directed=True)
    #bit_nd = map(lambda x: {'label':'n%d_0'%x, 'color': 'blue'}, range(1, nn + 1))
    for n in range(1, nn + 1):
        g.add_node(n, label = 'n%d_0'%n, color='blue', shape='circle')
    
    layout = g.layout("neato")
    g.draw('t{}.png'.format(0)) #, layout = layout)
    img_count = 1
    for ln in lns[1:]:
        nd = list(map(lambda x:(int(x[0]), int(x[1])), map(lambda x:x.split(':'), ln.split(','))))
        in_id, in_v = nd[0]#current input id, value
        #g = pgv.AGraph()
        #g.add_vertex(0)
        #for k in range(1, nn):
            #g.add_vertices(k)
            #g.add_edges([(0, k)])
        for bit_node, bit_v in nd[1:]:
            if in_id != bit_node:
                g.add_edge(in_id, bit_node, color = 'red')
                g.get_node(bit_node).attr['label'] = 'n%d_%d'%(bit_node, bit_v)
                g.draw('t{}.png'.format(img_count)) #, layout = layout)
                img_count += 1
        #layout = g.layout_reingold_tilford()
        #plot(g, layout = layout)#, opacity=0.1)
            #plx.show()

        #plt.show()
        #plt.savefig('t{}.png'.format(imgid))


