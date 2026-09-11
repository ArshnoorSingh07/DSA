# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sub.subject_name, count(e.subject_name)       as attended_exams 
    FROM Students s
    CROSS JOIN Subjects sub  -- Create first table of both essentials

    -- Now perform the task
    LEFT JOIN Examinations e
    ON sub.subject_name = e.subject_name
    AND s.student_id = e.student_id

    GROUP BY
        s.student_id,
        s.student_name,
        sub.subject_name
    
    ORDER BY 
        s.student_id, sub.subject_name;
