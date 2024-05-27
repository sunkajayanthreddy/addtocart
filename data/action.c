Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-IN,en;q=0.9");

	web_url("Catalog.action", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(24);

	lr_start_transaction("Jpet_Store_SC01_TC01_Sign_In");

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=C369785BB35F8BB8424FA1877643D377?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Sign_In",LR_AUTO);

	lr_start_transaction("Jpet_Store_SC01_TC01_Login");

	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid=C369785BB35F8BB8424FA1877643D377?signonForm=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=j2ee", ENDITEM, 
		"Name=password", "Value=j2ee", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=nCic7hU1NZxzKTTiv2bLlTy18z5r_Z_k88e94XjzJd4kuZId0idJE5f_JfZAiMeUMTRWGTQ3XvSb2Sq5TdxR8RnO9BzzmwbRUQHhEk0iXx4=", ENDITEM, 
		"Name=__fp", "Value=qzQF1uLtmfd2RD16Gj-GonlaChR9gQEnRYeVqGFeZ_kEKPxjXDkitd_BEMAmFG1z", ENDITEM, 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Login",LR_AUTO);

	lr_think_time(28);

	lr_start_transaction("Jpet_Store_SC01_TC01_Click_On_Fish");

	web_url("sm_fish.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Click_On_Fish",LR_AUTO);

	lr_think_time(29);

	lr_start_transaction("Jpet_Store_SC01_TC01_Click_On_Product_ID");

	web_url("FI-SW-02", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-02", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Click_On_Product_ID",LR_AUTO);

	lr_think_time(36);

	lr_start_transaction("Jpet_Store_SC01_TC01_Click_On_EST-3");

	web_url("EST-3", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewItem=&itemId=EST-3", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId=FI-SW-02", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Click_On_EST-3",LR_AUTO);

	lr_think_time(42);

	lr_start_transaction("Jpet_Store_SC01_TC01_cloick_On_Add_To_Cart");

	web_url("Add to Cart", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-3", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewItem=&itemId=EST-3", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_cloick_On_Add_To_Cart",LR_AUTO);

	lr_think_time(43);

	lr_start_transaction("Jpet_Store_SC01_TC01_Click_On_Product_To_Checkout");

	web_url("Proceed to Checkout", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId=EST-3", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Click_On_Product_To_Checkout",LR_AUTO);

	lr_think_time(32);

	lr_start_transaction("Jpet_Store_SC01_TC01_Click_On_Continue");

	web_submit_data("Order.action", 
		"Action=https://petstore.octoperf.com/actions/Order.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=order.cardType", "Value=Visa", ENDITEM, 
		"Name=order.creditCard", "Value=999 9999 9999 9999", ENDITEM, 
		"Name=order.expiryDate", "Value=12/03", ENDITEM, 
		"Name=order.billToFirstName", "Value=ABC", ENDITEM, 
		"Name=order.billToLastName", "Value=XYX", ENDITEM, 
		"Name=order.billAddress1", "Value=901 San Antonio Road", ENDITEM, 
		"Name=order.billAddress2", "Value=MS UCUP02-206", ENDITEM, 
		"Name=order.billCity", "Value=Palo Alto", ENDITEM, 
		"Name=order.billState", "Value=CA", ENDITEM, 
		"Name=order.billZip", "Value=94303", ENDITEM, 
		"Name=order.billCountry", "Value=USA", ENDITEM, 
		"Name=newOrder", "Value=Continue", ENDITEM, 
		"Name=_sourcePage", "Value=H_b2V9XHzI5IlyBXdGkg-J4kMwZf-LUWQiRdf9Pau64qHmMVjwnSX9p_mNwVD0P4p2g47SZiWwAJFaCRsiJtkUYDMvKT19dwAhpOXm2yfiM=", ENDITEM, 
		"Name=__fp", "Value=bID5MuogQ5vUWBZAUzocRtA820CRNk-TuxAQwb4gjVa9hSdVz6wHlf_YJAd1M_w3fh_ods8_k-DEpdIP6VJ_NCP4gMpVplbVnQCTllNHg6s1eNsTY2d3qw==", ENDITEM, 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Click_On_Continue",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("Jpet_Store_SC01_TC01_Click_On_Confirm");

	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Click_On_Confirm",LR_AUTO);

	lr_start_transaction("Jpet_Store_SC01_TC01_Click_On_Sign_Out");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Jpet_Store_SC01_TC01_Click_On_Sign_Out",LR_AUTO);

	return 0;
}