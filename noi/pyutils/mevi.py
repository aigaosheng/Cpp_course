#!/usr/bin/python3
# -*- coding: utf-8 -*-

import pygraphviz as pgv 
import json
import io
import argparse
from PIL import Image, ImageColor

slide_duration = 500
def nd_name(prefix, k):    
    return '{}{}'.format(prefix, k) if prefix else str(k)

def generateGif(image_slides, file_name):
    mx_x = max(map(lambda x:x.size[0], image_slides))
    mx_y = max(map(lambda x:x.size[1], image_slides))
    for k, img in enumerate(image_slides):
        img_bg = Image.new(mode = img.mode, size = (mx_x, mx_y), color = ImageColor.getcolor('white',mode = img.mode))
        y_shift=int((mx_y - img.size[1]) / 2)
        x_shift=int((mx_x - img.size[0]) / 2)
        img_bg.paste(img, box = (x_shift, y_shift, x_shift + img.size[0], y_shift + img.size[1]))
        image_slides[k] = img_bg
    image_slides[0].save(file_name, save_all=True, append_images=image_slides[1:], duration=slide_duration)#, loop = -1)

def graph2image(g, save_file = None):
    if save_file:
        g.draw(save_file, format = 'png', prog='dot') 
        fl = save_file
    else:
        img_bytes = g.draw(format = 'png', prog='dot') 
        fl = io.BytesIO(img_bytes)
    return Image.open(fl)

def buildGView(tree_node_file = '/home/gao/Work/Cpp_course/noi/tree/fenwickTree.json', save_gif_file = None):
    '''
    Input: tree_node_file, list input array and update steps of tree

    '''
    with open(tree_node_file) as fi:
        tree_step_query = json.load(fi)
    tree_step = tree_step_query[0]
    image_slides = []
    #cover image: BIT tree generate
    g_cov = pgv.AGraph()
    g_cov.add_node('cover', label = 'How fenwick tree building', color='black', shape='box', fontsize = 60)
    image_slides.append(graph2image(g_cov))

    #creat graph to hold input data & graph
    g_containter = pgv.AGraph(directed=True, label = "Tree update", nodesep = 0.2)
    #input array
    #img_count = 0
    g = g_containter.add_subgraph(name='cluster_0', label='Input array', rank='same')
    for k, v in enumerate(tree_step['input']):
        g.add_node(nd_name('i', k), label = 'i{}, {}'.format(k, v), color='blue', shape='circle')
        g.get_node(nd_name('i', k)).attr['fontsize'] = 20
        if k > 0:
            g.add_edge(nd_name('i', k-1), nd_name('i', k), color = 'red')
    #img_file = 't{}.png'.format(img_count)
    #g_containter.draw(img_file, prog='dot') #, layout = layout)
    #image_slides.append(Image.open(img_file))
    image_slides.append(graph2image(g_containter))
    #img_count += 1

    #create update step
    gt = g_containter.add_subgraph(name='cluster_1', label='Tree', rank='same', nodesep = 0.2)
    for k, _ in enumerate(tree_step['input'], start=1): #following algorithm, tree node index from 1
        gt.add_node(nd_name('t', k), label = 'T{}, {}'.format(k, 0), color='blue', shape='circle', ratio = "fill")
        gt.get_node(nd_name('t', k)).attr['fontsize'] = 20
    #root_id = len(tree_step['input']) + 1
    gt.add_node('root', label = 'root', color='blue', shape='rect', ratio='fill')
    gt.get_node('root').attr['fontsize'] = 20
    
    g_containter.graph_attr["rankdir"] = "LR"
    
    #img_file = 't{}.png'.format(img_count)
    #g_containter.draw(img_file, prog='dot') #, layout = layout)
    #image_slides.append(Image.open(img_file))
    #img_count += 1
    image_slides.append(graph2image(g_containter))

    #return 
    for k, iv in enumerate(tree_step['tree_update'], start=1):
        #iv is the update path when  input value is coming one-by-one, k: index position of input
        #if len(iv) == 1:
        #    iv = [iv]
        g.get_node(nd_name('i', k-1)).attr.update({'fillcolor':"grey",'style':'filled'})

        for pk, iv_path in enumerate(iv):
            tik, tiv = iv_path
            if pk > 0:
                gt.add_edge(nd_name('t', bit_node_0), nd_name('t', tik), color = 'green')
            bit_node_0 = tik
            #gt.get_node(tik).attr['label'] = 'T{}, i_{}, {}'.format(tik, tree_step['input'][k-1], tiv)
            #gt.get_node(nd_name('t', tik)).attr['label'] = 'T{},{}'.format(tik, tiv)
            gt.get_node(nd_name('t', tik)).attr['label'] = """<<b><font point-size='24'><font color="red">T{},{}</font></font></b>>""".format(tik, tiv)
            if pk == len(iv) - 1:
                gt.add_edge(nd_name('t', bit_node_0), 'root', color = 'green')
            #gt.get_node(nd_name('t', tik)).attr['fontcolor'] = 'grey'
            #img_file = 't{}.png'.format(img_count)
            #g_containter.draw(img_file, prog='dot') #, layout = layout)
            #image_slides.append(Image.open(img_file))
            image_slides.append(graph2image(g_containter))
            #img_count += 1

            #gt.get_node(nd_name('t', tik)).attr['label'] = old_label
            #gt.layout(prog='dot')
            #img_file = 't{}.png'.format(img_count)
            #g_containter.draw(img_file, prog='dot') #, layout = layout)
            #image_slides.append(Image.open(img_file))
            image_slides.append(graph2image(g_containter))

            #img_count += 1
    #add seperate image
    tree_query = tree_step_query[1]
    g_br = pgv.AGraph()
    g_br.add_node('query', label = 'Query fenwick tree to get range sum', color='black', shape='box', fontsize = 60)
    image_slides.append(graph2image(g_br))
    g_br = pgv.AGraph()
    '''g_br.add_node('query_range', label = 'Sum between {} and {}'.format(tree_query['input'][0], tree_query['input'][1]), color='black', shape='box', fontsize = 60)
    g_br.add_node('query_last', label = 'First get sum untill last {}'.format(tree_query['input'][1]), color='black', shape='box', fontsize = 40, style = 'dashed')
    g_br.add_node('query_last', label = 'Second get sum untill first {}'.format(tree_query['input'][0]), color='black', shape='box', fontsize = 40, style = 'dashed')'''
    g_br.add_node('query_msg', label = """<1.Get sum untill last {}<br></br> 2. Get sum untill first {}.<br></br> 3.Answer = First_sum - Second_sum>""".format(tree_query['input'][1], tree_query['input'][0]), color='black', shape='box', fontsize = 40, style = 'dashed')

    image_slides.append(graph2image(g_br))
    #image_slides[-1].show()
    #show step
    g_containter_q = pgv.AGraph(g_containter.to_string(), nodesep = 0.2) #directed=True, label = "Query fenwick tree")
    g_containter.graph_attr["rankdir"] = "LR"
    g_tree = g_containter_q.add_subgraph(name='cluster_2', label='BIT tree', rank='same')
    g_tree.add_node('query_range', label = 'Query to get sum between {} and {}'.format(tree_query['input'][0], tree_query['input'][1]), color='black', shape='plaintext', fontsize = 40)
    g_tree.add_node('query_last', label = 'Sum between 1 and {}:'.format(tree_query['input'][1]), color='black', shape='plaintext', fontsize = 40)
    g_tree.add_node('query_first', label = 'Sum between 1 and {}:'.format(tree_query['input'][0]), color='black', shape='plaintext', fontsize = 40)
    g_tree.add_node('Answer', label = '??', color='black', shape='plaintext', fontsize = 40)
    image_slides.append(graph2image(g_containter_q))
    #read last point query
    g_tree.get_node('query_first').attr['style'] = 'invis'
    g_tree.get_node('Answer').attr['style'] = 'invis'
    for pk, iv_path in enumerate(tree_query['query_last']):
        tik, tiv = iv_path
        #hight current node
        my_nd = g_containter_q.get_node('t{}'.format(tik))
        my_nd.attr.update({'fillcolor':"darkorange1",'style':'filled'})
        #update current sum
        g_tree.get_node('query_last').attr['label'] = """<Sum between 1 and {}: <b><font color='green'>{}</font></b>>""".format(tree_query['input'][1], tiv)
        image_slides.append(graph2image(g_containter_q))

        #image_slides[-1].show()
    #query first
    g_tree.get_node('query_first').attr['style'] = g_tree.get_node('query_last').attr['style'] 
    for pk, iv_path in enumerate(tree_query['query_first']):
        tik, tiv = iv_path
        #hight current node
        my_nd = g_containter_q.get_node('t{}'.format(tik))
        my_nd.attr.update({'fillcolor':"darkorange1",'style':'filled'})
        #update current sum
        g_tree.get_node('query_first').attr['label'] = """<Sum between 1 and {}: <b><font color='green'>{}</font></b>>""".format(tree_query['input'][0], tiv)
        image_slides.append(graph2image(g_containter_q))

        #image_slides[-1].show()
    #answer
    g_tree.get_node('Answer').attr['style'] = g_tree.get_node('query_last').attr['style'] 
    tiv = tree_query['query_last'][-1][1] - tree_query['query_first'][-1][1]
    #update current sum
    g_tree.get_node('Answer').attr['label'] = """<Answer: <b><font color="green">{}</font></b>>""".format(tiv)
    image_slides.append(graph2image(g_containter_q))
    #image_slides[-1].show()

    #create gif
    generateGif(image_slides, save_gif_file)
 
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', action='store', help='json-format data to build graph')
    parser.add_argument('--save', action='store', help='gif file name')
    parser.add_argument('--duration', type = int, action='store', help='each slide duration')
    
    me_arg = parser.parse_args()
    try:
        #me_arg.input = '/home/gao/Work/Cpp_course/noi/tree/fenwickTree.json'
        #me_arg.save = 't3.gif'
        if me_arg.duration:
            slide_duration = me_arg.duration
        else:
            slide_duration = 500
            
        if me_arg.input and me_arg.save:
            buildGView(me_arg.input, me_arg.save)
        else:
            parser.print_help()
    except:
        parser.print_help()
