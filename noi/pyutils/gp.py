import networkx as nx
import matplotlib.pyplot as plt

with open('/home/gao/Work/Cpp_course/noi/tree/fenwickTree.txt') as fi:
    for imgid, ln in enumerate(fi):
        nd = ln.strip('\n').split('img')
        in_id, in_v = nd[0].split(':')#current input id, value
        g = nx.Graph()
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

            g.add_edges_from(ed)
        pos = nx.spring_layout(g)
        nx.draw_networkx_nodes(g, pos, node_size=700)

        # edges
        nx.draw_networkx_edges(g, pos, edgelist=g.edges(), width=6)

        # labels
        nx.draw_networkx_labels(g, pos, font_size=20, font_family="sans-serif")

        #plt.show()
        plt.savefig('t{}.png'.format(imgid))


