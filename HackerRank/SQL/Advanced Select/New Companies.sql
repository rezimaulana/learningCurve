select
    Company.company_code,
    Company.founder,
    count(distinct Lead_Manager.lead_manager_code),
    count(distinct Senior_Manager.senior_manager_code),
    count(distinct Manager.manager_code),
    count(distinct Employee.employee_code)
from
    Company
    left join Lead_Manager on Company.company_code = Lead_Manager.company_code
    inner join Senior_Manager on Lead_Manager.lead_manager_code = Senior_Manager.lead_manager_code
    inner join Manager on Senior_Manager.senior_manager_code = Manager.senior_manager_code
    inner join Employee on Manager.manager_code = Employee.manager_code
group by
    Company.company_code,
    Company.founder
order by
    Company.company_code;