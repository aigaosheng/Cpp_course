#!/usr/bin/python3
# -*- coding: utf-8 -*-

import pygraphviz as pgv 
import json
import matplotlib.pyplot as plt

def buildGView(tree_node_file = '/home/gao/Work/Cpp_course/noi/tree/fenwickTree.json'):
    '''
    Input: tree_node_file, list input array and update steps of tree

    '''
    with open(tree_node_file) as fi:
        tree_step = json.load(fi)
    #inpput array
    img_count = 0
    g = pgv.AGraph(directed=True)
    for k, v in enumerate(tree_step['input']):
        g.add_node(k, label = 'i{}, {}'.format(k, v), color='blue', shape='circle')
        if k > 0:
            g.add_edge(k-1, k, color = 'red')
    g.graph_attr["rankdir"] = "TB"
    g.graph_attr["splines"] = "ortho"
    g.graph_attr["ordering"] = "out"
    g.graph_attr['ratio'] = 'fill'
    g.layout(prog='dot')
    #layout = g.layout("neato")    
    g.draw('t{}.png'.format(img_count)) #, layout = layout)
    img_count += 1

    #create update step
    gt = pgv.AGraph(directed=True)
    #gt.add_node('input', label = 'input=', color='black', shape='rect', ratio='fill')
    for k, _ in enumerate(tree_step['input'], start=1): #following algorithm, tree node index from 1
        gt.add_node(k, label = 'T{}, {}'.format(k, 0), color='blue', shape='circle', ratio = "fill")
    #root_id = len(tree_step['input']) + 1
    gt.add_node('root', label = 'root', color='blue', shape='rect', ratio='fill')

    
    gt.graph_attr["rankdir"] = "TB"
    gt.graph_attr["splines"] = "ortho"
    gt.graph_attr["ordering"] = "out"
    #gt.graph_attr['size'] = '500, 500'

    gt.layout(prog='dot')
    
    gt.draw('t{}.png'.format(img_count)) #, layout = layout)
    img_count += 1

    for k, iv in enumerate(tree_step['tree_update'], start=1):
        #iv is the update path when  input value is coming one-by-one, k: index position of input
        #if len(iv) == 1:
        #    iv = [iv]
        #gt.get_node('input').attr['label'] = 'input={}_{}'.format(k-1, tree_step['input'][k-1])
        for pk, iv_path in enumerate(iv):
            tik, tiv = iv_path
            if pk > 0:
                gt.add_edge(bit_node_0, tik, color = 'green')
            bit_node_0 = tik
            #gt.get_node(tik).attr['label'] = 'T{}, i_{}, {}'.format(tik, tree_step['input'][k-1], tiv)
            gt.get_node(tik).attr['label'] = 'T{},{}'.format(tik, tiv)
            if pk == len(iv) - 1:
                gt.add_edge(bit_node_0, 'root', color = 'green')
            gt.get_node(tik).attr['fontcolor'] = 'grey'
            gt.draw('t{}.png'.format(img_count)) #, layout = layout)
            img_count += 1

            gt.get_node(tik).attr['fontcolor'] = 'black'
            gt.layout(prog='dot')
            gt.draw('t{}.png'.format(img_count)) #, layout = layout)
            img_count += 1
    #TO DO. write last GT as Tree

if __name__ == '__main__':
    buildGView()