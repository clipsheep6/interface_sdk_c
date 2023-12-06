#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2023 Huawei Device Co., Ltd.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


import sys
import os
import json
import unittest
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "../../src")))
from coreImpl.check import check
from coreImpl.diff import diff_file


class TestMethods(unittest.TestCase):
    def test_check(self):
        test_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "..\\"))
        test_case_path = os.path.join(test_path, "ut\\check")
        output_path = os.path.join(test_path, "output\\check")
        expect_path = os.path.join(test_path, "expect\\check")
        for dirpath, dirnames, filenames in os.walk(test_case_path):
            for item in filenames:
                if not item.endswith(".h"):
                    continue
                file_name = item.split('.')[0]
                test_case_file_name = os.path.join(dirpath, item)
                check_result = check.get_check_result_list([test_case_file_name])
                output_file_name = os.path.join(output_path, "{}.json".format(file_name))
                check.write_in_txt(check_result, output_file_name)
                expect_file_name = os.path.join(expect_path, "{}.json".format(file_name))
                if not os.path.exists(expect_file_name):
                    continue
                expect_file = open(expect_file_name)
                expect_file_content = expect_file.read()
                expect_file.close()
                out_json = check.result_to_json(check_result)
                self.assertEqual(out_json, expect_file_content,
                                 f"\n{test_case_file_name} case is error.\n" +
                                 f"{output_file_name} is out file.\n" +
                                 f"{expect_file_name} is expect out file")

    def test_diff(self):
        test_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "..\\"))
        test_case_old_path = os.path.join(test_path, "ut\\diff\\old")
        test_case_new_path = os.path.join(test_path, "ut\\diff\\new")
        output_path = os.path.join(test_path, "output\\diff")
        expect_path = os.path.join(test_path, "expect\\diff")
        old_file_list = os.listdir(test_case_old_path)
        for case_name in old_file_list:
            output_file_name = os.path.join(output_path, "{}.json".format(case_name))
            test_case_old_dir = os.path.join(test_case_old_path, case_name)
            test_case_new_dir = os.path.join(test_case_new_path, case_name)
            diff_result = diff_file.global_assignment(test_case_old_dir, test_case_new_dir)
            diff_json = diff_file.result_to_json(diff_result)
            diff_file.write_in_txt(diff_json, output_file_name)
            expect_file_name = os.path.join(expect_path, "{}.json".format(case_name))
            if not os.path.exists(expect_file_name):
                continue
            expect_file = open(expect_file_name)
            expect_file_content = expect_file.read()
            expect_file.close()
            self.assertEqual(diff_json, expect_file_content,
                             f"\n{case_name} case is error.\n" +
                             f"\n{test_case_old_dir} is old case dir.\n" +
                             f"\n{test_case_new_dir} is new case dir.\n" +
                             f"{output_file_name} is out file.\n" +
                             f"{expect_file_name} is expect out file")


if __name__ == '__main__':
    unittest.main()
