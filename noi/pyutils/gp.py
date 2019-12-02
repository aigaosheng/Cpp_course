import networkx as nx
import matplotlib.pyplot as plt
from networkx.drawing.nx_agraph import graphviz_layout

def save2image(g, name):
    #pos = nx.spring_layout(g)
    #nx.draw_networkx_nodes(g, pos, node_size=700)
    # edges
    #nx.draw_networkx_edges(g, pos, edgelist=g.edges(), width=6)

    # labels
    #nx.draw_networkx_labels(g, pos, font_size=20, font_family="sans-serif")

    #nx.draw(g)
    #plt.show()
    pos=graphviz_layout(g, prog='dot')
    nx.draw(g, pos, with_labels=False, arrows=False)

    plt.savefig(name)
    plt.clf()

with open('/home/gao/Work/Cpp_course/noi/tree/fenwickTree.txt') as fi:
    lns = fi.readlines()
    #
    img_prefix = 't'
    nds = map(lambda x: int(x), lns[0].strip('\n').strip(',').split(','))
    g = nx.Graph()
    g.add_nodes_from(nds)
    save2image(g, '{}0.png'.format(img_prefix))
    #g.clear()

    for imgid, ln in enumerate(lns[1:]):
        vv = ln.strip('\n').split(',')
        in_id, in_v = vv[0].split(':')#current input id, value
        in_id = int(in_id)
        in_v = int(in_v)
        #g = nx.Graph()
        #g.add_nodes_from(nds)
        for i_v in vv[1:]:
            nd, nv = i_v.split(':')
            nd = int(nd)
            nv = int(nv)
            if in_id != nd:
                g.add_edge(in_id, nd)
        save2image(g, '{}{}.png'.format(img_prefix, imgid+1))
        #g.clear()
        #break


