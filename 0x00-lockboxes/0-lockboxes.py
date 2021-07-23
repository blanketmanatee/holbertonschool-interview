#!/usr/bin/python3
    ''' can all boxes be unlocked '''
    def canUnlockAll(boxes)
        ''' create a list of keys '''
        seen = [False] * len(boxes)
        seen[0] = True
        stack = [0]
        while stack:  #While we have keys...
            node = stack.pop() # get the next key 'node'
            for nei in boxes[node]: # For every key in box # 'node'...
                if not seen[nei]: # ... that hasn't been used yet
                    seen[nei] = True # mark that we've opened the box
                    stack.append(nei) # add the key to the todo list
        return all(seen) # Return true if we've visited every box