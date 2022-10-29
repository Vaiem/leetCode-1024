/* TASK leetCode № 1024 : You are given a series of video clips from a sporting event that lasted time seconds. These video clips can be overlapping with each other and have varying lengths.

Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti and ended at endi.

We can cut these clips into segments freely.

    For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. If the task is impossible, return -1.*/

#pragma once
#include<vector>

class Solution {
public:
    int videoStitching(std::vector<std::vector<int>>& clips, int time) {
        int maxItem = INT_MIN;

        int lenghtVideo = clips[0].size() - 1;

        for (size_t i = 0; i < clips.size(); i++)
        {
            maxItem = std::max(maxItem, clips[i][lenghtVideo]);
        }
        if (maxItem < time)
        {
            return -1;
        }
        
        std::vector<std::vector<int>> res;
        
        int startItem = 0;
        int endItem = INT_MIN;

        while (startItem < time)
        {
            std::vector<int> currentRes(lenghtVideo + 1);
            for (size_t i = 0; i < clips.size(); i++)
            {
                if (clips[i][0] <= startItem)
                {
                    endItem = std::max(endItem,clips[i][lenghtVideo]);
                    if (endItem > time)
                    {
                        endItem = time;
                        break;
                    }
                }
            }

            if (startItem == endItem)
            {
                return -1;
            }
            currentRes.push_back(startItem);
            currentRes.push_back(endItem);

            res.push_back(currentRes);

            startItem = endItem;
        }

        return res.size();
        
    }
};