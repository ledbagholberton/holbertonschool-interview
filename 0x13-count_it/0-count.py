#!/usr/bin/python3
""" Exporting csv files"""
import json
import requests
import sys
after = None


def count_words(subreddit, word_list):
    """Count the titles found with wordlist in subreddit"""
    my_list = recurse(subreddit)
    my_dict = {}

    if my_list is True:
        for word in word_list:
            my_dict[word] = 0

    for title in my_list:
        title_split = title.split(" ")

    for iter in title_split:
        for iter_split in word_list:
            if iter.lower() == iter_split.lower():
                my_dict[iter_split] += 1

    for key, val in sorted(my_dict.items(),  key=lambda x:x[1], reverse=True):
        if val != 0:
            print("{} : {}".format(key, val))


def recurse(subreddit, hot_list=[]):
    """ recurse is a function that return hot list from
        a subreddit"""
    global after
    username = 'ledbag123'
    password = 'Reddit72'
    user_pass_dict = {'user': username, 'passwd': password, 'api_type': 'json'}
    headers = {'user-agent': '/u/ledbag123 API Python for Holberton School'}
    parameters = {"after": after}
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    client = requests.session()
    client.headers = headers
    r = client.get(url, allow_redirects=False, params=parameters)
    if r.status_code == 200:
        next_ = r.json().get('data').get('after')
        if next_ is not None:
            after = next_
            recurse(subreddit, hot_list)
            list_titles = r.json().get('data').get('children')
            for title_ in list_titles:
                hot_list.append(title_.get('data').get('title'))
            return hot_list
    else:
        return (None)
