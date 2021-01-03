import re

epoch_patt = re.compile(r"\[[0-9]+]")
ndcg_patt = re.compile(r"ndcg@[0-9]+: 0.[0-9]+")


def parse_log(line):
    epoch_hits = re.findall(epoch_patt, line)
    if not epoch_hits:
        return
    ndcg_hits = re.findall(ndcg_patt, line)
    if not ndcg_hits:
        return

    log_info = {"epoch": int(epoch_hits[0][1:-1])}
    ndcg_dict = {ndcg.split(": ")[0]: float(ndcg.split(": ")[1]) for ndcg in ndcg_hits}
    log_info.update(ndcg_dict)
    return log_info
    
# {'epoch': 1, 'ndcg@1': 0.613588, 'ndcg@3': 0.662982, 'ndcg@5': 0.706414}
# {'epoch': 2, 'ndcg@1': 0.626327, 'ndcg@3': 0.66951, 'ndcg@5': 0.714824}
# {'epoch': 3, 'ndcg@1': 0.617834, 'ndcg@3': 0.67654, 'ndcg@5': 0.719002}
# {'epoch': 4, 'ndcg@1': 0.58811, 'ndcg@3': 0.665337, 'ndcg@5': 0.714892}
# {'epoch': 5, 'ndcg@1': 0.592357, 'ndcg@3': 0.678974, 'ndcg@5': 0.72254}
