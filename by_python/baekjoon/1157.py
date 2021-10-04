s_list = list(input().upper())
u_list = list(set(s_list))
ret = []

for ch in u_list :
    ret.append(s_list.count(ch))

print(u_list[ret.index(max(ret))] if ret.count(max(ret)) < 2 else '?')


