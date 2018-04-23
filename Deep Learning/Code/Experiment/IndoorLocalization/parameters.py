#!/bin/python3
# coding: utf-8

"""
参数设置
"""

__author__ = "bovenson"
__email__ = "szhkai@qq.com"
__date__ = "2018-04-20 13:25"


P_RF_NUM = 50     # 参考点数量
P_A = -30         # 距离接入点 1 米处场强
P_q = 2.1         # 室内场强因数
P_sigma = 1.0     # 正态分布方差
P_sample_single_num = 600       # 单定位参考点训练样本数量
P_sample_single_valida = 600    # 单定位参考点验证集数量

P_sample_single_item_count = 30  # 每条记录使用RSS记录数量
P_img_width = 300       # 图片宽
P_img_height = 300      # 图片高
P_img_scale = 3
