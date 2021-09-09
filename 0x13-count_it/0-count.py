#!/usr/bin/python3
"""Contains count_words function to query reddit API"""
import requests


def count_words(subreddit, word_list, after=None, count={}):
    """Counts the number of times a word appears in a subreddit's hot list"""
    if after:
        request = requests.get(
            'https://www.reddit.com/r/{}/hot.json?after={}'.format(
                subreddit, after),
            headers={'User-Agent': 'CortRobinson'},
            allow_redirects=False)
    else:
        request = requests.get(
            'https://www.reddit.com/r/{}/hot.json'.format(subreddit),
            headers={'User-Agent': 'CortRobinson'},
            allow_redirects=False)

    data = request.json().get('data')

    for word in word_list:
        word = word.lower()
        if word not in count.keys():
            count[word] = 0

    children = data.get('children')
    for child in children:
        title = (child.get('data')).get('title').lower().split(' ')
        for word in word_list:
            word = word.lower()
            count[word] += title.count(word)

    after = data.get('after')
    if after:
        return count_words(subreddit, word_list, after, count)

    sorted_subs = sorted(count.items(), key=lambda x: (-x[1], x[0]))
    for i in sorted_subs:
        if i[1] > 0:
            print(f'{i[0]}: {i[1]}')
